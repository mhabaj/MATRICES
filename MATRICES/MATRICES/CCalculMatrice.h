#pragma once
#include "CMatrice.h"

template <typename Type> class CCalculMatrice
{
private:
	CCalculMatrice() {};

public:
	static CMatrice<Type> transpose(CMatrice<Type> mat);
};