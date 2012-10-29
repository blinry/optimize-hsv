#include "optimizer.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]) {
    string source_img(argv[1]);
    string target_img = source_img+"~";
    string image_viewer = "firefox ";
    string convert_cmd = "convert ";

    Vec3f v(50, 50, 50);
    NelderMeadOptimizer<3> o(10);
    float score;

    o.insert(Vec3f(200,50,50));
    o.insert(Vec3f(50,200,50));
    o.insert(Vec3f(50,50,200));
    o.insert(Vec3f(20,20,20));

    system((image_viewer+target_img).c_str());

    while (!o.done()) {
        ostringstream v0, v1, v2;
        v0 << v[0];
        v1 << v[1];
        v2 << v[2];
        string cmd;
        cmd = (convert_cmd+source_img).append(" -modulate ").append(v0.str()).append(",").append(v1.str()).append(",").append(v2.str()).append(" ").append(target_img).append("~");
        cout << cmd << endl;
        system(cmd.c_str());
        system(string("cp ").append(target_img).append("~ ").append(target_img).c_str());

        cout << "Score? ";
        cin >> score;
        v = o.step(v, score);
    }

    return 0;
}
