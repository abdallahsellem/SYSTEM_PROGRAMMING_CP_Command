#include<unistd.h>
#include<fcntl.h>
 int main(int argc, char *argv[])
{
	if(argc<3)
	{
		return 1 ;
	}
	
	int FdSrcFile =open(argv[1],O_RDONLY) ;
	if(FdSrcFile==-1)
	{
		return 2 ;

	}
	
	int FdSrcFile2 =open(argv[2],O_CREAT|O_WRONLY,S_IRUSR) ;
	if(FdSrcFile2==-1)
	{
		return 3 ;

	}
	char buf[100] ;
	ssize_t char_count ;
	while((char_count =read(FdSrcFile,buf,sizeof(buf)))!=0)
	{
write(FdSrcFile2,buf,char_count) ;
	}

	return 0;
}