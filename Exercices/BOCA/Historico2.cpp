#include <iostream>
#include <vector>

struct Subject {
    std::string id;
    bool students[3] = {false, false, false};
};

int main() {
    std::vector<Subject> v;
    Subject tmp;
    bool checker;
    int N[3], i, j;
    while(true) {
        std::cin >> N[0] >> N[1] >> N[2];
        if(N[0]==0 && N[1]==0 && N[2]==0) break;
        for(i=0; i<3; i++) {
            checker = false;
            for(j=0; j<N[i]; j++) {
                std::cout << j << " < " << N[i] << std::endl;
                std::cin >> tmp.id;
                tmp.students[i] = true;
                for(auto &item:v){
                    if(item.id==tmp.id){
                        item.students[i] = true;
                        checker = true;
                    }
                }
                if(checker==false){
                    v.push_back(tmp);
                }
                tmp.students[i] = false;
            }
        }
    }
    return 0;
}
