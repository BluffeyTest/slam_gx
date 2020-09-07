#include <pangolin/pangolin.h>

void function(){
    std::cout << "Hello pangolin" << std::endl;
}

int main() {
    pangolin::CreateWindowAndBind("Main",640,480);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
            pangolin::ProjectionMatrix(640,480,420,420,320,320,0.2,100),
            pangolin::ModelViewLookAt(2,0,2, 0,0,0, pangolin::AxisY)
    );

    pangolin::Handler3D handler(s_cam);
    pangolin::View& d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)
            .SetHandler(&handler);

    pangolin::CreatePanel("ui").SetBounds(0.0, 1.0, 0.0, pangolin::Attach::Pix(180));//创建

    pangolin::Var<bool> a_button("ui.A_Button", false, false);//设置一个按钮，默认值为false，最后一个false表示按钮形式
    pangolin::Var<double> a_double("ui.A_Double", 3, 0, 5);//设置一个double的、可拖动变换值的玩意(不知道咋形容)！
    pangolin::Var<int> a_int("ui.A_Int", 2, 0, 5);//设置一个int的、可拖动变换值的玩意
    pangolin::Var<std::function<void(void)>> reset("ui.Reset", function);//设置一个按钮，用于调用function函数

    while( !pangolin::ShouldQuit() )
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        d_cam.Activate(s_cam);

        if (pangolin::Pushed(a_button)){//如果a_button按钮被点，就运行if里面的语句
            std::cout << "You tough a_buttom" << std::endl;
            a_double = 0;
            a_int = 0;
        }

        glColor3f(1.0, 1.0, 1.0);
        pangolin::glDrawColouredCube();

        pangolin::FinishFrame();
    }

    return 0;
}