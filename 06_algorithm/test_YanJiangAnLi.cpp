#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <map>
#include <numeric>
#include <deque>
#include "functional"
#include "iterator" // 输出流迭代器
using namespace std;
using std::random_shuffle;

class Speaker
{
public:
    string m_name;
    int m_score[3];

public:
    Speaker(/* args */){};
    ~Speaker(){};
};

// 产生选手
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v1)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_shuffle(str.begin(), str.end());

    for (int i = 0; i < 24; i++)
    {
        Speaker tmp;
        tmp.m_name = "Player:";
        tmp.m_name = tmp.m_name + str[i];
        mapSpeaker.insert(pair<int, Speaker>(i + 100, tmp));
    }

    for (int i = 0; i < 24; i++)
    {
        v1.push_back(i + 100); //参加比赛的人员名单
    }

    return 0;
}

// 选手抽签
int speech_contest_draw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
    return 0;
}

// 选手比赛
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
    // 小组的比赛得分给记录下来，求出前三名，和后三名
    multimap<int, int, greater<int>> multimapGroup;
    int tmpcount = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        tmpcount++;
        // 打分

        deque<int> dscore;
        for (int j = 0; j < 10; j++) //10个评委打分
        {
            int score = 50 + rand() % 50;
            dscore.push_back(score);
        }
        sort(dscore.begin(), dscore.end()); //排序
        dscore.pop_front();                 //去除最低分
        dscore.pop_back();                  //去除最高分

        // 求平均分
        int scoreAverage = accumulate(dscore.begin(), dscore.end(), 0) / dscore.size();
        mapSpeaker[*it].m_score[index] = scoreAverage; // 选手得分
        multimapGroup.insert(pair<int, int>(scoreAverage, *it));
        // 处理分组
        if (tmpcount % 6 == 0)
        {
            std::cout << "The Score of Group " << tmpcount / 6 << std::endl;
            for (multimap<int, int, greater<int>>::iterator it2 = multimapGroup.begin();
                 it2 != multimapGroup.end(); it2++)
            {
                //编号 姓名 得分
                cout << it2->second << "\t" << mapSpeaker[it2->second].m_name << "\t" << mapSpeaker[it2->second].m_score[index] << endl;
            }
            // 前三名晋级
            while (multimapGroup.size() > 3)
            {
                multimap<int, int, greater<int>>::iterator it1 = multimapGroup.begin();
                v2.push_back(it1->second); // 把前三名放到晋级名单v2中
                multimapGroup.erase(it1);
            }
            multimapGroup.clear(); // 清空本小组比赛成绩；
        }
    }

    return 0;
}

// 查看每一轮的结果
int speech_contest_print(int index, vector<int> &v2, map<int, Speaker> &mapSpeaker)
{
    printf("the list of  %d is \n", index + 1);
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        //编号 姓名 得分
        cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
    }

    return 0;
}
int main()
{
    map<int, Speaker> mapSpeaker; // 参加比赛的选手

    vector<int> v1; // 第一轮演讲名单
    vector<int> v2; // 第一轮演讲名单
    vector<int> v3; // 第一轮演讲名单
    vector<int> v4; // 最后前三名

    // 产生选手 得到第一轮选手的比赛名单
    GenSpeaker(mapSpeaker, v1);

    //第一轮 选手抽签 选手比赛 查看比赛结果
    cout << " start the game:" << endl;
    cin.get();

    speech_contest_draw(v1);
    speech_contest(0, v1, mapSpeaker, v2);
    speech_contest_print(0, v2, mapSpeaker);

    //第二轮 选手抽签 选手比赛 查看比赛结果
    cout << "\n start the game:" << endl;
    cin.get();
    speech_contest_draw(v2);
    speech_contest(1, v2, mapSpeaker, v3);
    speech_contest_print(1, v3, mapSpeaker);

    //第三轮 选手抽签 选手比赛 查看比赛结果
    cout << "\n start the game:" << endl;
    cin.get();
    speech_contest_draw(v3);
    speech_contest(2, v3, mapSpeaker, v4);
    speech_contest_print(2, v4, mapSpeaker);

    system("pause");
    return 0;
}