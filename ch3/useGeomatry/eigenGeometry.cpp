#include<iostream>
#include<Eigen/Geometry>

using namespace std;
using namespace Eigen;

#define Mat Eigen::Matrix
#define Mat3d Eigen::Matrix3d

typedef Eigen::Vector3d object3d;

int main(int argc, char const *argv[])
{
	//单位矩阵
	Mat3d R = Mat3d::Identity();
	cout<<"the Identity is:"<<endl;
	cout<<R<<endl;

	AngleAxisd R_vector(M_PI/4,Vector3d(0,0,1));//沿Z轴旋转45度
	cout.precision(3);
	cout<<"rotation mat  = "<<endl;
	cout<<R_vector.matrix()<<endl;

	Vector3d v(1,0,0);//旋转前的坐标
	Vector3d v_rotate = R_vector.matrix() * v;
	cout<<"v_rotate = "<<endl;
	cout<<v_rotate<<endl;

	Vector3d euler_angle = R_vector.matrix().eulerAngles(2,1,0);//转换为ZYX顺序欧拉角
	cout<<"yaw pitch roll  = "<<endl;
	cout<<euler_angle.transpose()<<endl;//输出转置
	cout<<euler_angle<<endl;//输出不转置

	//欧氏变换矩阵使用Eigen::Isometry
	Isometry3d T = Isometry3d::Identity();
	T.rotate(R_vector);
	T.pretranslate(Vector3d(1,3,4));
	cout<<"tansform mat = "<<endl;
	cout<<T.matrix()<<endl;

	Vector3d v_trans = T*v;
	cout<<"v_trans = "<<endl;
	cout<<v_trans.transpose()<<endl;


	//仿射变换Eigen::Affine3d和射影变换Eigen::Projective3d需要再学习的，
	//但是目前没有一堆比较好的例子。


	//四元数
	//可以直接把AngleAxis赋值给四元素
	Quaterniond q=Quaterniond(R_vector);
	cout<<"Quaterniond form rotation vector = "<<endl;
	cout<<q.coeffs().transpose()<<endl;

	q = Quaterniond(R_vector.matrix());
	cout<<"Quaterniond form rotation vector = "<<endl;
	cout<<q.coeffs().transpose()<<endl;

	//使用四元数旋转一个向量，只要重载一个乘法
	v_rotate = q*v;//数学上是qvq^{-1}
	cout<<"v_rotate = "<<endl;
	cout<<v_rotate<<endl;


 












	return 0;
}