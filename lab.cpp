// cs102 lab
// build as lab4.cgi   and copy it to /usr/lib/cgi-bin
// keep lab4.html in the lab4 directory
// receive 2 integers multiply them and display result
#include <iostream>
#include <sstream>

void code(int);
void barcode(int);

int main()
{
	//use environment variable named in QUERY_STRING
	std::string s = getenv("QUERY_STRING");
	// parse the string to get the integers
	//  requires 2 newlines             1           2
	std::cout << "Content-Type:text/html\n" << std::endl;
	std::cout << "<H3>After entering your zip code </H3>" << std::endl;
	std::cout << "<H2 style = 'color:blue'>here is your bar code!!</H2>" 
	          << std::endl;
	
	std::istringstream iss(s);
	//     z    =    94538
	int z;  char c;
	iss >> c >> c >> z;
	std::cout << "&nbsp;&nbsp;&nbsp;Your zip code is: "<< z <<"<br>";
	int r = z;
	std::cout<<"&nbsp;&nbsp;&nbsp;Your bar code is: |";
	code(z);
	std::cout<<"|";
	return 0;
}

/*
compute check code: expects a zip code as string or integer, 
return either char of integer for the check digit.
	 The check digit is calculated by summing the five digits of
	  the zip code and finding a digit that would bring the 
	  total to a number which is a multiple of 10.
*/

/**
 compile every digit of the zip code and then output its bar code
 \param cd the zip code
 \return cc the check code 
*/
void code(int c)
{
    //every digit of the zip code
    int c_d;
    c_d=(c-(c%10000))/10000;
    barcode(c_d);
    
    int total=0;
    total=total+c_d;

    c_d=((c-c%1000)/1000)%10;
    barcode(c_d);
    
    total=total+c_d;

    c_d=((c-(c%100))/100)%10;
    barcode(c_d);
    
    total=total+c_d;

    c_d=((c%100)-(c%10))/10;
    barcode(c_d);
    
    total=total+c_d;

    c_d=c%10;
    barcode(c_d);
    
    total=total+c_d;

    int cc;
    if(total%10!=0)
    {
        cc=10-(total%10);
        barcode(cc);
    }
    else
    {
        cc=0;
        barcode(cc);
    }
    
    
    return;

}



/**
 output the bar code of every digit of the zip code
 \param cd is the digit of the zip code
 */
 
 
void barcode(int cd)
{    
    if (cd==1)
    {
        std::cout<<":::||";
    }
    if (cd==2)
    {
        std::cout<<"::|:|";
    }
    if (cd==3)
    {
        std::cout<<"::||:";
    }
    if (cd==4)
    {
        std::cout<<":|::|";
    }
    if (cd==5)
    {
        std::cout<<":|:|:";
    }
    if (cd==6)
    {
        std::cout<<":||::";
    }
    if (cd==7)
    {
        std::cout<<"|:::|";
    }
    if (cd==8)
    {
        std::cout<<"|::|:";
    }
    if (cd==9)
    {
        std::cout<<"|:|::";
    }
    if (cd==0)
    {
        std::cout<<"||:::";
    }
    return;
}

