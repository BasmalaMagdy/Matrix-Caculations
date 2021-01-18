#include <iostream>
#include <string>
#include <math.h>
#include<cstdlib>
#include <sstream>
#include<complex>

using namespace std;

int main()
{
	int len, len2, i, j, r = 0, rr = 0, ro, roo = 0, row, row2, n, b = 0, c = 0, cc = 0, col, col2, y1 = 0, x1 = 0, y2 = 0, x2 = 0, h = 0, sp, hh, x, xi;
	string array1[100][100], array2[100][100];
	string s, ro1, ro2, z, st, op, ss, rel,rel2, im,im2;
	float ar[100][100], br[100][100], ai[100][100], bi[100][100],cr[100][100],ci[100][100];
	float acr[100][100], bcr[100][100],aci[100][100],bci[100][100];
	
	//cout << "enter the first array" << "\n";
	getline(cin, s);
	len = s.length();
	//check

	//calculate no. of row
	for (i = 0; i < len; i++)
	{
		if (s[i] == ';')
		{
			r++;
		}
		ro = r + 1;
	}
	for (i = 1; i < len; i++)
	{
		if (s[i] == ';')
		{
			ro1 = s.substr(1, (i - 1));
			row = ro1.length();
			break;
		}
	}

	//calculate no.of col.
	for (i = 0; i < row; i++)
	{
		if (s[i] == ' ')
		{
			c += 1;
			sp = c;
			col = c + 1;
		}
	}
	//check
	for (i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			h += 1;
			hh = h;
		}
		if (s[i] == ';' || s[i] == ']')
		{
			if (hh != sp)
			{
				cout << "ERROR";
				return 0;
			}
			h = 0;
		}

	}
	for (i = 0; i < len; i++)
	{
		if (s[i] == ' ' || s[i] == ';' || s[i] == ']')
		{
			for (n = i - 1; s[n] != '[' && s[n] != ']' && s[n] != ' ' && s[n] != ';'; n--)
			{
				b = n;
			}

			st = s.substr(b, (i - b));
			z = st;
			x = z.length();
			for (int n = 0; n < x; n++)
			{
				if (z[n] == '+'|| z[n] == '-')
				{
					rel = z.substr(0, n);
					ar[x1][y1] = atof(rel.c_str());
					im = z.substr(n);
					xi = im.length();
					im = im.substr(0, xi - 1);
					ai[x1][y1] = atof(im.c_str());

				}
			}

			//array1[x1][y1] = z;
			//cout << ai[x1][y1] << "\n";

			y1 += 1;

		}

		if (s[i] == ';')
		{
			x1 += 1;
			y1 = 0;
		}
	}
	/*for (int i = 0; i < ro; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::complex<float>coma(ar[i][j], ai[i][j]);
			cr[i][j] = real(coma)+1;
			cout<< cr[i][j] <<"\n" ;
		}

	}*/


	//operators----------------------------------------------------
	//cout << "please enter operator" << "\n";
	getline(cin, op);
	char mark = op[0];
	if (mark == '+' || mark == '-' || mark == '*' || mark == '/')
	{
		//second array---------------------------------------------------------------
	   //cout << "enter the second array " << "\n";
		getline(cin, ss);
		len2 = ss.length();
		//calculate no. of row
		for (i = 0; i < len2; i++)
		{
			if (ss[i] == ';')
			{
				rr++;
			}
			roo = rr + 1;
		}
		for (i = 1; i < len2; i++)
		{
			if (ss[i] == ';')
			{
				ro2 = ss.substr(1, (i - 1));
				row2 = ro2.length();
				break;
			}
		}

		//calculate no.of col.
		for (i = 0; i < row2; i++)
		{
			if (ss[i] == ' ')
			{
				cc += 1;
				col2 = cc + 1;
			}
		}
		//------------------------------------------------------------------------
		for (i = 0; i < len2; i++)
		{
			if (ss[i] == ' ' || ss[i] == ';' || ss[i] == ']')
			{
				for (n = i - 1; ss[n] != '[' && ss[n] != ']' && ss[n] != ' ' && ss[n] != ';'; n--)
				{
					b = n;
				}

				st = ss.substr(b, (i - b));
				z = st;
				x = z.length();
				for (int n = 0; n < x; n++)
				{
					if (z[n] == '+'|| z[n] == '-')
					{
						rel2 = z.substr(0, n);
						br[x2][y2] = atof(rel2.c_str());
						im2 = z.substr(n);
						xi = im2.length();
						im2 = im2.substr(0, xi - 1);
						bi[x2][y2] = atof(im2.c_str());

					}
				}
				//cout << array2[x][y] << "\n";

				y2 += 1;

			}

			if (ss[i] == ';')
			{
				x2 += 1;
				y2 = 0;
			}
		}
	}
	switch (mark)
	{
	case'+':
		if (ro != roo || col != col2)
		{
			cout << "ERROR" << "\n";
			return 0;
		}
		//calculate the addition of real&imaj part
		for (int i=0; i < ro; i++)
		{
			for (int j=0; j < col; j++)
			{
				std::complex<float>coma(ar[i][j], ai[i][j]);
				acr[i][j] = real(coma);
				aci[i][j] = imag(coma);
			}

		}
		for (int i=0; i < roo; i++)
		{
			for (int j=0; j < col2; j++)
			{
				std::complex<float>comb(br[i][j], bi[i][j]);
				bcr[i][j] = real(comb);
				bci[i][j] = imag(comb);
			}

		}
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ci[i][j] = aci[i][j] + bci[i][j];
				cr[i][j] = acr[i][j] + bcr[i][j];
			}
		}
		cout << "[";
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ostringstream f;             //cr to string
				string strcr;
				f << cr[i][j];
				strcr = f.str();

				ostringstream ff;           //ci to string
				string strci;
				ff << ci[i][j];
				strci = ff.str();

				if (ci[i][j] > 0||ci[i][j]==0)
				{cout << strcr << "+" << strci << "i";}
				
				if(ci[i][j]<0)
				{
					cout << strcr << strci << "i";
				}


				if ((j + 1) != col)
				{
					cout << " ";
				}

			}
			if ((i + 1) != ro)
			{
				cout << ";";
			}
		}
		cout << "]";

		break;

	case'-':
		if (ro != roo || col != col2)
		{
			cout << "ERROR" << "\n";
			return 0;
		}
		//calculate the sub of real&imaj part
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::complex<float>coma(ar[i][j], ai[i][j]);
				acr[i][j] = real(coma);
				aci[i][j] = imag(coma);
			}

		}
		for (int i = 0; i < roo; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				std::complex<float>comb(br[i][j], bi[i][j]);
				bcr[i][j] = real(comb);
				bci[i][j] = imag(comb);
			}

		}
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ci[i][j] = aci[i][j] - bci[i][j];
				cr[i][j] = acr[i][j] - bcr[i][j];
			}
		}
		cout << "[";
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ostringstream f;             //cr to string
				string strcr;
				f << cr[i][j];
				strcr = f.str();

				ostringstream ff;           //ci to string
				string strci;
				ff << ci[i][j];
				strci = ff.str();

				if (ci[i][j] > 0 || ci[i][j] == 0)
				{
					cout << strcr << "+" << strci << "i";
				}

				if (ci[i][j] < 0)
				{
					cout << strcr << strci << "i";
				}

				if ((j + 1) != col)
				{
					cout << " ";
				}

			}
			if ((i + 1) != ro)
			{
				cout << ";";
			}
		}
		cout << "]";

		break;

	case'*':
		if (col != roo)
		{
			cout << "ERROR" << "\n";
			return 0;
		}

		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::complex<float>coma(ar[i][j], ai[i][j]);
				acr[i][j] = real(coma);
				aci[i][j] = imag(coma);
			}

		}
		for (int i = 0; i < roo; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				std::complex<float>comb(br[i][j], bi[i][j]);
				bcr[i][j] = real(comb);
				bci[i][j] = imag(comb);
			}

		}

		for (int x3 = 0; x3 < ro; x3++)
		{
			for (int y3 = 0; y3 < col; y3++)
			{
				cr[x3][y3] = 0;
				ci[x3][y3] = 0;
			}
		}
	
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				for (int v = 0; v < col; v++)//variable
				{
					cr[i][j] += ((acr[i][v] * bcr[v][j])-(aci[i][v]*bci[v][j]));
				}
			}
		}
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				for (int v = 0; v < col; v++)//variable
				{
					ci[i][j] += ((acr[i][v] * bci[v][j])+(bcr[v][j]*aci[i][v]));
				}
			}
		}
		cout << "[";
		for (int i = 0; i < ro; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				ostringstream f;             //cr to string
				string strcr;
				f << cr[i][j];
				strcr = f.str();

				ostringstream ff;           //ci to string
				string strci;
				ff << ci[i][j];
				strci = ff.str();
				

				if (ci[i][j] > 0 || ci[i][j] == 0)
				{
					cout << strcr << "+" << strci << "i";
				}

				if (ci[i][j] < 0)
				{
					cout << strcr << strci << "i";
				}

				if ((j + 1) != col2)
				{
					cout << " ";
				}

			}
			if ((i + 1) != ro)
			{
				cout << ";";
			}
		}
		cout << "]";

		break;
	}

	system("pause");
}
