//Random c++ program for understanding the concepts of C++
#include<iostream>
#include<string.h>
using namespace std;
class bookstore{
	public:

		char type[20];
		char name[25];
		int id;
	    int costprice;
	    int mrp;
	    int quantity;

	void getdata(){
        int c;
        hello:
            cout<<"\n\t-----Bark book store------\n";
            cout<<"\nTypes of books in store:";
            cout<<"\n...................\n1-Comic\n2-Subjective\n";
            cin>>c;

        switch(c){

                int w;
            case 1:
                cout<<"\n\nTypes of Comics:\n";
                cout<<"1-Actions\n2-Adventure\n3-Mystery\n";
                cin>>w;

                switch(w){
                    hell:
                    case 1:cout<<"    -------ACTION COMICS-------";
                    super:
                        cout<<"\n\nSeries available in store:\n";
                        cout<<"1-Batman\n2-Superman\n3-Spiderman\n4-The Hulk\n5-Justice League\n6-Avengures\n7-The Fantastic Four\n";
                        int y;
                        cin>>y;
                switch(y)
     		{   case 1:cout<<"\t\t     ^__^\n";
     			cout<<"\t ************    *************\n";
				cout<<"\t  *      BATMAN COMICS      *\n";
				cout<<"\t   *.......         .......*\n";
				cout<<"\t           *       *\n";
				cout<<"\t\t    *     *\n";
				cout<<"\t\t     *   *\n";
				cout<<"\t\t      * *\n";
				cout<<"\t\t       * \n";

     			break;
     			case 2:cout<<"\t  ********\n";
     			       cout<<"\t *SUPERMAN*\n";
     			       cout<<"\t  *COMICS*\n";
     			       cout<<"\t   *    *\n";
     			       cout<<"\t    *  *\n";
     			       cout<<"\t     **\n";
				break;
				case 3:cout<<"    ------- SPIDERMAN COMICS -------";
				cout<<"\n\t\t   |";
				cout<<"\n\t\t   |";
				cout<<"\n\t\t*  |  *\n";
				cout<<"\t    *\t   |      *\n";
				cout<<"\t\t*  |  *\n";
				cout<<"\t\t   *\n";
				cout<<"\t\t*    *\n";
				cout<<"\t   *\t           *\n";
				cout<<"\t\t*     *\n";
				break;
				case 4:cout<<"    ------- THE HULK COMICS -------";
				cout<<"\n\t\t ____      ____";
				cout<<"\n\t\t|    |    |    |";
				cout<<"\n\t\t|    |____|    |";
				cout<<"\n\t\t|   THE  HULK  |";
				cout<<"\n\t\t|     ____     |";
				cout<<"\n\t\t|    |    |    |";
				cout<<"\n\t\t|____|    |____|";
				break;
				case 5:cout<<"    ------- JUSTICE LEAGUE SERIES -------";
				break;
				case 6:cout<<"    ------- AVENGERS SERIES -------";
				cout<<"\n\t\t         *";
				cout<<"\n\t\t        * *";
				cout<<"\n\t\t       *   *";
				cout<<"\n\t\t      *******";
				cout<<"\n\t\t     *       *";
				cout<<"\n\t\t    *   ***   *";
				cout<<"\n\t\t   *   *   *   *";
				cout<<"\n\t\t  *   *     *****";
				cout<<"\n\t\t *   *";
				cout<<"\n\t\t*****";
				break;
				case 7:cout<<"    ------- THE FANTASTIC FOUR COMICS -------";
				cout<<"\n\t\t          *";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t        ***";
				cout<<"\n\t\t       ****";
				cout<<"\n\t\t      ** **";
				cout<<"\n\t\t     **  **";
				cout<<"\n\t\t    **   **";
				cout<<"\n\t\t   **    **";
				cout<<"\n\t\t  *************";
				cout<<"\n\t\t ***************";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t         **";
				cout<<"\n\t\t         **";
				break;
				default:cout<<"Invalid input...\n";
     		goto super;
     		}
			 break;
     		case 2:cout<<"    -------ADVENTURE COMICS-------";
     		poing:
     		cout<<"\n\nSeries available in store:\n";
     		cout<<"\n1-Peter Pan\n2-Dora-The Explorer\n3-Monsters.inc\n4-Aladin-The Arabian Nights";
     		cout<<"\n5-Phineas & Ferb\n6-Chicken Little\n7-Timon & Pumba\n";
     		int o;
     		cin>>o;
     		switch(o)
     		{
			 case 1:cout<<"    -------PETER PAN SERIES-------";
			 case 2:cout<<"    -------DORA-THE EXPLORER SERIES-------";
			 case 3:cout<<"    -------MONSTERS.INC SERIES-------";
			 case 4:cout<<"    -------ALADIN SERIES-------";
			 case 5:cout<<"    -------PHINEAS & FERB SERIES-------";
			 case 6:cout<<"    -------CHICKEN LITTLE SERIES-------";
			 case 7:cout<<"    -------TIMON & PUMBA SERIES-------";
     		 break;
     		default:cout<<"Invalid input...\n";
     		goto poing;
     	    }
     		break;
     		case 3:cout<<"    -------MYSTERY COMICS-------";
     		saw:
     		cout<<"\n\nSeries available in store:\n";
     		cout<<"\n1-Sherlock Holmes\n2-Robinhood\n3-Kim Possible\n4-Defective Detectives\n";
     		int u;
     		cin>>u;
     		switch(u)
     		{
     			case 1:cout<<"    -------SHERLOCK HOLMES SERIES-------";
     			case 2:cout<<"    -------ROBINHOOD SERIES-------";
     			case 3:cout<<"    -------KIM POSSIBLE SERIES-------";
     			case 4:cout<<"    -------DEFECTIVE DETECTIVES SERIES-------";
     			break;
     			default:cout<<"Invalid input...\n";
     		    goto saw;
     		}
     		break;
     		default:cout<<"Invalid input...\n";
     		goto hell;
     	}
     	break;
     	case 2:cout<<"\n\nTypes of subjectve books:\n";
     	cout<<"1-Fiction\n2-Non-fiction\n";
     	cin>>w;
     	switch(w)
     	{   home:
     		case 1:cout<<"   -------FICTION BOOKS-------";
     		break;
			 case 2:cout<<"  -------NON-FICTION BOOKS-------";
     		break;
     		default:cout<<"Invalid input...\n";
     		goto home;
     	}
     	break;
     	default:cout<<"Try again......\n";
     	goto hello;
     }
		 cout<<"\n\nEnter the book id: ";
		 cin>>id;
		 cout<<"\nName: ";
		 cin>>name;
		 cout<<"\nCost Price: ";
		 cin>>costprice;
		 cout<<"\nMRP: ";
		 cin>>mrp;
	}
};
class info : public bookstore
{
	int age,total;
	char genre[10];
	public:
		void getdata()
		{
			bookstore::getdata();
			cout<<"\n\nThe genre of book: ";
			cin>>genre;
			cout<<"\nThe age group: ";
			cin>>age;
		}
		void display()
		{
			cout<<"\n";
		}
};
class trade :public info
{
	int qty,sp,profit,cp,pid;
	public:
		void getdata()
		{
			info::getdata();
			cout<<"\n\nThe quantity of book bought: ";
			cin>>qty;
			sp=(mrp*qty);
			cout<<"\n\nThe total selling price    : "<<sp;
			cp=((costprice)*qty);
			cout<<"\n\nThe total cost price       :"<<cp;
		    cout<<"\n          Purchase Id:bbookstore";
		    cin>>pid;
		}
		int calculate()
		{
			profit=sp-cp;
		}
		void display()
		{
			info::display();
			cout<<"\nNAME        "<<name<<"\nCOST PRICE  "<<costprice<<"\nMRP         "<<mrp<<"\nBOOK ID:    "<<id
			<<"\nQUANTITY    "<<qty<<"\nPURCHASE ID "<<pid<<"\nPROFIT      "<<profit;
		}

};

int main()
{
  trade a1;
  a1.getdata();
  a1.calculate();
  a1.display();

}
