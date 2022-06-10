#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
struct ques
{
    string line[5];
};
struct topics
{
    struct ques question[21];
};
struct subjects
{
    struct topics topic[3];
};
class question_bank_class
{
    string enrolment_no;
    string name;
    string branch;
    int subject_choosed;
    int topic_choosed;
    int total_marks = 0;
    int marks[21];
    struct subjects subject[4];
public:
    question_bank_class()
    {
        cout << " \n                         \t\t~~~~ Welcome to our Quiz ~~~~      \n"
             << endl;
        cout << "Rules for attempting the quiz.     \n " << endl;
        cout << "   1. Each ques consists of 1 marks and there are 20 question total." << endl;
        cout << "   2. There is no negative marking involved." << endl;
        cout << "   3. Once you have written your answer you can not change it.\n"
             << endl;
        cout << "Enter Your Name : " << endl;
        cin>>ws;
        getline(cin, name);
        cout << "Enter Your Branch : " << endl;
        cin>>branch;
        cout << "Enter the enrollment number :" << endl;
        cin >> enrolment_no;
    }
    void start_quiz();
    void timer(int x);
    void get_question();   
    void show_ques();    
    void shuffle();     
    void result_marksheet();  
    void review();    
};
 void question_bank_class::timer(int x){       
    int hour=0,min=0,sec=x;      
    while(true){
        cout<<sec;
       if(sec==0 && min!=0){
            min--;
            sec=60;           
            }            
        else if(min==0 && sec==0)          
          break;
          sec--;
          cout<<"...";        
        sleep(1);       // alarm(1);
    }
   }
void question_bank_class::start_quiz()
    {
        get_question(); //-------------------> function to take ques from file
        cout<<endl << "  Choose a subject\n"
             << endl;
        cout << "    1) Data structure" << endl;
        cout << "    2) Oops" << endl;
        cout << "    3) BEEE" << endl;
        cin >> subject_choosed;
        cout<<endl;
        switch (subject_choosed)
        {
        case 1:
            cout <<"Datastructure: " << endl;
            cout << " Choose a Topic:  "
                 << endl;
            cout << "   1)Stack and Queue" << endl;
            cout << "   2)Linked List" << endl;
            cin >> topic_choosed;
            
                if(topic_choosed==1)
                   cout<<endl<<"                                   Datastructure---->Stack and Queue"<<endl<<endl;
                else
                   cout<<endl<<"                                   Datastructure---->Linked List"<<endl<<endl;
            show_ques();

            break;
        case 2:
            cout << "OOPS:  "
                 << endl;
            cout << "  Choose a Topic:  "
                 << endl;
            cout << "    1)Class and Objects" << endl;
            cout << "    2)Abstraction" << endl;
            cin >> topic_choosed;
            if(topic_choosed==1)
                   cout<<endl<<"                                   OOPS---->Class and Objects"<<endl<<endl;
            else
                   cout<<endl<<"                                   OOPS---->Abstraction"<<endl<<endl;
            show_ques();
            break;
        case 3:
            cout << "BEEE:   " 
                 <<endl;
            cout << "  Choose a Topic:  "
                 << endl;
            cout << "    1)D.C. Circuits" << endl;
            cout << "    2)Capacitors" << endl;
            cin >> topic_choosed;
            if(topic_choosed==1)
                   cout<<endl<<"                                   BEEE---->D.C. Circuits"<<endl<<endl;
            else
                   cout<<endl<<"                                   BEEE---->Capacitors"<<endl<<endl;
            show_ques();
            break;
        default:
            cout << "******Invalid Input********\n\n";
            break;
        }
    }
    void question_bank_class::get_question()
    { ///**************** storing question from file to our program*********************

        ifstream ques_file("check.txt");
        for (int s = 1; s < 4; s++)
        {
            for (int t = 1; t < 3; t++)
            {
                for (int q = 1; q < 21; q++)
                {
                    for (int l = 1; l < 5; l++)
                    {
                        getline(ques_file, subject[s].topic[t].question[q].line[l]);
                    }
                }
            }
        }
    }
   void question_bank_class::show_ques()
    {
        shuffle(); //--------------------> shuffling ques
        string ans;
        for (int q = 1; q < 21; q++)
        {
            cout << endl
                 << q << ") ";
            for (int l = 1; l < 4; l++)
            {
                cout << subject[subject_choosed].topic[topic_choosed].question[q].line[l] << endl;
            }
          cout <<endl<< "Ans : ";
            cin >> ans;
            // cout << "   Your ans is : \n\n" << ans << endl;
            string real_ans = subject[subject_choosed].topic[topic_choosed].question[q].line[4];

            if (ans == real_ans) // checking if the ans is correct or wrong
            {
                marks[q] = 1;
                total_marks++;
            }
            else
            {
                marks[q] = 0;
            }
        }
    }
   void question_bank_class::shuffle()
    {
        srand(time(0));
        int a = rand() % 8; //a=4

        struct ques temp;

        for (int i = 1; i + a < 21; i++)
        {

            temp = subject[subject_choosed].topic[topic_choosed].question[i];
            subject[subject_choosed].topic[topic_choosed].question[i] = subject[subject_choosed].topic[topic_choosed].question[i + a];
            subject[subject_choosed].topic[topic_choosed].question[i + a] = temp;
            i = i + a;
        }
    }
    void question_bank_class::result_marksheet()
    {
        string subject_choosed_name, topic_choosed_name;
        switch (subject_choosed)
        {
        case 1:
            switch (topic_choosed)
            {
            case 1:
                subject_choosed_name = "Data structure";
                topic_choosed_name = "Stack and Queue";
                break;
            case 2:
                subject_choosed_name = "Data structure";
                topic_choosed_name = "Linkedlist";
                break;
            }
            break;
        case 2:
            switch (topic_choosed)
            {
            case 1:
                
                subject_choosed_name = "OOPS";
                topic_choosed_name = "Topic:Class and Objects";
                break;
            case 2:
                
                subject_choosed_name = "OOPS";
                topic_choosed_name = "Abstraction";
                break;
            }
            break;
        case 3:
            switch (topic_choosed)
            {
            case 1:
                
                subject_choosed_name = "BEEE";
                topic_choosed_name = "D.C. Circuits";

                break;
            case 2:
                
                subject_choosed_name = "BEEE";
                topic_choosed_name = "capacitors";
                break;
            }
            break;
        }
       string result;
        if(total_marks>=7)
         result="PASS";
        else
         result="FAIL";

         cout<<endl<<"Kindly, wait for few seconds while we calculate your results...";
         timer(10);
         cout<<endl<<endl;
         cout << "              * * * * * *        * * * * *         * * * * *          * * * * *         * * * * * *" << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        sleep(1);
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                      Gwalior                                      *" << endl;
        sleep(1);
        cout << "                                   Madhav Institute Of Technology And Science                              " << endl;
        sleep(1);
        cout << "                                                 Marksheet Of Exam                                  " << endl;
        sleep(1);
        cout << "                                                                                                   " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        sleep(1);
        cout << "                                    Name Of  Student :           " << name << "                            " << endl;
        sleep(1);
        cout << "                                    Enrollment Number :          " << enrolment_no << "                    " << endl;
        sleep(1);
        cout << "                                    Branch Of  Student :         " << branch << "                          " << endl;
        sleep(1);
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        sleep(1);
        cout << "                                    Subject  :                   " << subject_choosed_name << "            " << endl;
        sleep(1);
        cout << "                                    Topic :                      " << topic_choosed_name << "              " << endl;
        sleep(1);
        cout << "                                    Number Of question:           20                                       " << endl; 
        sleep(1);
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        sleep(1);
        cout << "                                    Total marks :               " << total_marks << "                      " << endl;
        sleep(1);
        cout << "                                    Percentage :                " << (total_marks/20.0)*100<<"%"<< "       " << endl;
        sleep(1);
        cout << "                                    Result :                    " << result << "                           " << endl;   
        sleep(1);
        cout << "              *                                                                                   * " << endl;                                                                                                
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        cout << "              *                                                                                   * " << endl;
        sleep(1);
        cout << "              * * * * * *         * * * * *         * * * * *         * * * * *         * * * * * *" << endl;
        cout << "\n     Do you want the review of your quiz   " << endl;
        cout << "          1)Yes                2)No" << endl;
        int review_check;
        cin >> review_check;
        if (review_check == 1)
            review();
    }
    void question_bank_class::review()
    {
        cout<<endl;
    cout<<"                                     *******************Review*******************\n\n";
    {       
        for (int q = 1; q < 10; q++)
        {
            if (marks[q] == 1)
                cout <<"                                         "<< q << "    ---> correct" << endl;
            else
                cout <<"                                         "<< q << "    ---> wrong (the correct option is " << subject[subject_choosed].topic[topic_choosed].question[q].line[4] << ")" << endl;
        }
        for (int q = 10; q < 21; q++)
        {
            if (marks[q] == 1)
                cout <<"                                         "<< q << "   ---> correct" << endl;
            else
                cout <<"                                         "<< q << "   ---> wrong (the correct option is " << subject[subject_choosed].topic[topic_choosed].question[q].line[4] << ")" << endl;
        }
    }
    }
int main(){
x:
    question_bank_class question_bank;
    question_bank.start_quiz();
    question_bank.result_marksheet();
    cout <<endl<<endl<< "                          Do you want to reattempt the quiz" << endl;
    cout << "                                      1) yes                 2)no" << endl;
    int reattempt_quiz;
    cin >> reattempt_quiz;
    if (reattempt_quiz == 1){
        system("cls");
        goto x;
    }
    return 0;}

