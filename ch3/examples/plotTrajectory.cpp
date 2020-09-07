
#include <Eigen/Core>

#include <pangolin/pangolin.h>
#include <unistd.h>

using namespace std;
using namespace Eigen;

std::string trajectory_file = "../trajectory.txt";


void DrawTrajectory(
	std::vector<Isometry3d,Eigen::aligned_allocator<Isometry3d>> //这种用法还是第一次见
	);


int main(int argc, char const *argv[])
{

	std::vector<Isometry3d,Eigen::aligned_allocator<Isometry3d>> v_poses;
	ifstream fin(trajectory_file);
	if (!fin)
	{
		cout<<"can't find the file at "<<trajectory_file<<endl;
		return 1;
	}

	while(!fin.eof())
	{
		double time, tx, ty, tz, qx, qy, qz, qw;
		fin>>time>>tx>>ty>>tz>>qx>>qy>>qz>>qw;
		Isometry3d Twr(Quaterniond(qw,qx,qy,qz));
		Twr.pretranslate(Vector3d(tx,ty,tz));
		v_poses.push_back(Twr);
	}
	cout<<"read total "<<v_poses.size()<<" pose entries."<<endl;

	//绘制轨迹
	DrawTrajectory(v_poses);

	cout<<"import pangolin right!"<<endl;
	return 0;
}

/**

*/
void DrawTrajectory(std::vector<Isometry3d,Eigen::aligned_allocator<Isometry3d>> v_poses)
{
	//create pangolin window and plot the trajectory
	pangolin::CreateWindowAndBind("trajectory viewer",1024,768);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	pangolin::OpenGlRenderState s_cam(
		pangolin::ProjectionMatrix(1024,768,500,500,512,389,0.1,1000),
		pangolin::ModelViewLookAt(0,-0.1,-1.8,0,0,0,0.0,-1.0,0.0)
		);
	pangolin::View &d_cam = pangolin::CreateDisplay()
		.SetBounds(0.0,1.0,0.0,1.0,-1024.0f/768.0f)
		.SetHandler(new pangolin::Handler3D(s_cam));

	while(pangolin::ShouldQuit() == false)
	{
		glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
		d_cam.Activate(s_cam);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glLineWidth(2);
		for(size_t i=0;i<v_poses.size();i++)
		{
			Vector3d Ow = v_poses[i].translation();
			Vector3d Xw = v_poses[i]*(0.1 * Vector3d(1,0,0));
			Vector3d Yw = v_poses[i]*(0.1 * Vector3d(0,1,0));
			Vector3d Zw = v_poses[i]*(0.1 * Vector3d(0,0,1));
			glBegin(GL_LINES);

			glColor3d(1.0, 0.0, 0.0);
			glVertex3d(Ow[0],Ow[1],Ow[2]);
			glVertex3d(Xw[0],Xw[1],Xw[2]);
			
			glColor3d(0.0, 1.0, 0.0);
			glVertex3d(Ow[0],Ow[1],Ow[2]);
			glVertex3d(Yw[0],Yw[1],Yw[2]);

			glColor3d(0.0, 0.0, 1.0);
			glVertex3d(Ow[0],Ow[1],Ow[2]);
			glVertex3d(Zw[0],Zw[1],Zw[2]);

			glEnd();
		}

		for(size_t i = 0;i<v_poses.size();i++)
		{
			glColor3d(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			auto p1 =v_poses[i], p2 = v_poses[i+1];
			glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
			glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
			glEnd();
		}

		pangolin::FinishFrame();
		usleep(5000);
	}


}