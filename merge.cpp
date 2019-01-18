template <typename Iterator1, typename Iterator2>
Iterator2 merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output)
{
	f1 = first1;
	f2 = first2;
	while (f1 != last1 && f2 != last2)
	{
		if (*f1 < *f2)
		{
			*output = *f1;
			++f1;
		}
		else
		{
			*output = *f2;
			++f2;
		}
		++output;
	}
	while (f1 != last1)
	{
		*output = *f1;
		++f1;
		++output;
	}
	while (f2 != last2)
	{
		*output = *f2;
		++f2;
		++output;
	}
	return output;
}
