<<<<<<< HEAD
=======
#include "CCalculMatrice.h"

template<typename Type>
CMatrice<Type> CCalculMatrice<Type>::transpose(CMatrice<Type> mat)
{
	CMatrice<Type> result(mat.getCol(), mat.getLig());
	for (int iloopLig = 0; iloopLig < result.getLig(); iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < result.getCol(); iloopCol++)
		{
			result.MATModifierElem(mat.getElem(iloopCol, iloopLig), iloopLig, iloopCol);
		}
	}
	return result;
}
>>>>>>> parent of c16fd76... ez constructor
