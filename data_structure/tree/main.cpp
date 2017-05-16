#include<iostream>
#include"tree.h"
/*
∞¥À≥–Ú ‰»Î 20 10 30 5 15 25 35
–Œ◊¥				20
			10				30
		5		15		25		35



*/
using namespace std;
int main()
{
	{
		Tree tree1;
		int mod;
		int flag = 0;
		while (1) {
			mod = chose_mod();

			switch (mod)
			{
			case 1:tree1.insert_more(); break;
			case 2:	tree1.preordder(); break;
			case 3:tree1.inorder(); break;
			case 4:	tree1.postorder(); break;
			case 5:tree1.breathfirst(); break;
			case 6:flag = 1; break;
			default:cout << "please chose mod again!!!\n";
			}

			if (flag == 1)
				break;

		}

	
		cout << "quit the tree system!!!" << endl;


	}
		system("pause");
		return 0;
	
}