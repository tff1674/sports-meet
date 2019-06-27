#include <iostream>
using namespace std;
struct college {//ѧԺ
    int n;//ѧԺ���
    int score=0;//�ܵ÷�
    int totol=0;//��������
    int number[10];//ѧ������
    int champion=0;//�ھ�
    int second=0;//�Ǿ�
    int third=0;//����
    int rank=0;
    int r=0;
    int k=0;
};
struct match {//������Ŀ
    int beyond;//������¼��
    int rank[6];//�ý�����
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
    int n, m;//��������ѧԺ��
    cin >> n;
    cin >> m;
    int Score[6] = {8, 6, 4, 3, 2, 1};

    struct college college1[m];
    struct match match[n];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < 10; i++) {
            college1[j].number[i] = 0;
        }
    for (int i = 0; i < m; i++)//����ѧԺ����
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
    for (int i = 0; i < n; i++)//���������Ŀ������
    {
        int q, p;
        cin >> q;
        match[i].beyond = q;
        for (int j = 0; j < 6; j++) {
            cin >> p;
            match[i].rank[j] = p;
        }
    }

    for (int i = 0; i < n; i++)//���������Ŀ������,n��������Ŀ
    {
        int tscore[6] = {8, 6, 4, 3, 2, 1};
        int j;
        for (j = 0; j < match[i].beyond; j++) {
            tscore[j] = 2 * tscore[j];
        }
        for (j = 0; j < 6; j++)//j=�����ĺ�����
            for (int k = 0; k < m; k++)//ѧԺ��Ŀ
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
        cout << "���" << college1[i].n << endl;
        cout << "�ھ�:" << college1[i].champion << endl;
        cout << "�Ǿ�:" << college1[i].second << endl;
        cout << "����:" << college1[i].third << endl;
    }

    quicksort(college1, 0, m - 1);


    cout << "�������" << endl;
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

