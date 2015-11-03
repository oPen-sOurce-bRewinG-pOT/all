int lpyear(int i)
{
	int result;
	int yr=i-2001;
	//if (yr<0)
	//	yr=-yr;
	int nolp=yr/4;
	if (i<2001)
		nolp--;
	return nolp;
}
