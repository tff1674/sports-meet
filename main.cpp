#include <iostream>
using namespace std;
struct college {//学院
    int n;//学院编号
    int score=0;//总得分
    int totol=0;//参赛人数
    int number[10];//学生号码
    int champion=0;//冠军
    int second=0;//亚军
    int third=0;//季军
    int rank=0;
    int r=0;
    int k=0;
};
struct match {//比赛项目
    int beyond;//超出记录数
    int rank[6];//得奖排名
};

void quicksort(struct college college[], int low, int high)
{
    struct college e=college[low];
    int i=low,j=high;
    int h=3;
    while (i<j) {
        while (i < j && college[j].score <= e.score)
        {
            if(college[j].score < e.score) j--;
            else if(college[j].score == e.score)
            {
                if(college[j].champion < e.champion)
                {
                    j--;
                    break;
                }
                else if(college[j].champion == e.champion)
                {
                    if(college[j].second < e.second)
                    {
                        j--;
                        break;
                    }
                    else if(college[j].second == e.second){
                        if(college[j].third < e.third)
                        {
                            j--;
                            break;
                        }
                        else if(college[j].third == e.third){
                            if(college[j].totol < e.totol)
                            {
                                j--;
                                break;
                            }
                            else if(college[j].totol== e.totol){
                                j--;
                                break;
                            }
                            else break;
                        }
                        else break;
                    }
                    else break;
                }
                else break;
            }
            else break;
        }
        if (i < j) college[i++] = college[j];
        while (i < j && college[j].score > e.score) if(college[j].score > e.score) i++;
        if (i < j) college[j--] = college[i];
       /* for(int i=0;i<high;i++){
            cout<<"this:"<<i+1<<" "<<college[i].n<<"rank:"<<college[i].rank<<endl;
        }*/
    }
    college[i]=e;
    if(low<i-1) quicksort(college, low, i-1);
    if(i+1<high) quicksort(college, i+1, high);
}


int main() {
    int n, m;//比赛数，学院数
    cin >> n;
    cin >> m;
    int Score[6] = {8, 6, 4, 3, 2, 1};

    struct college college1[m];
    struct match match[n];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < 10; i++) {
            college1[j].number[i] = 0;
        }
    for (int i = 0; i < m; i++)//输入学院数据
    {
        college1[i].n = i + 1;
        int p, q;
        cin >> p;
        college1[i].totol = p;
        for (int j = 0; j < p; j++) {
            cin >> q;
            college1[i].number[j] = q;
        }
    }
    for (int i = 0; i < n; i++)//输入比赛项目的数据
    {
        int q, p;
        cin >> q;
        match[i].beyond = q;
        for (int j = 0; j < 6; j++) {
            cin >> p;
            match[i].rank[j] = p;
        }
    }

    for (int i = 0; i < n; i++)//输入比赛项目的数据,n个比赛项目
    {
        int tscore[6] = {8, 6, 4, 3, 2, 1};
        int j;
        for (j = 0; j < match[i].beyond; j++) {
            tscore[j] = 2 * tscore[j];
        }
        for (j = 0; j < 6; j++)//j=比赛的号码数
            for (int k = 0; k < m; k++)//学院数目
                for (int q = 0; q < college1[k].totol; q++) {
                    if (match[i].rank[j] == college1[k].number[q]) {
                        college1[k].score = college1[k].score + tscore[j];
                        if (j == 0) college1[k].champion++;
                        if (j == 1) college1[k].second++;
                        if (j == 2) college1[k].third++;
                    }
                }
    }


    for (int i = 0; i < m; i++) {
        cout << "score:" << college1[i].score << endl;
        cout << "编号" << college1[i].n << endl;
        cout << "冠军:" << college1[i].champion << endl;
        cout << "亚军:" << college1[i].second << endl;
        cout << "季军:" << college1[i].third << endl;
    }

    quicksort(college1, 0, m - 1);


    cout << "输出数据" << endl;
   /* for (int i = 0; i < m; i++) {
        cout << i << " " << college1[i].n << "rank:" << college1[i].rank << endl;
    }*/
    for (int i = 0; i < m; i++) {

        if ((college1[i].champion == college1[i - 1].champion) && (college1[i].second == college1[i - 1].second) &&
                                   (college1[i].third == college1[i - 1].third)
                                   && (college1[i].totol == college1[i - 1].totol))

        {
                college1[i].r = college1[i - 1].r;
                cout << college1[i].r << " " << college1[i].n << endl;
        }
        else if (i== 0)
        {
            college1[i].r = i + 1;
            cout << college1[i].r << " " << college1[i].n << endl;
        }

        else {
            college1[i].r=college1[i-1].r+1;
            cout<<college1[i].r<<" "<<college1[i].n<<endl;
        }


    }
    return 0;
}

