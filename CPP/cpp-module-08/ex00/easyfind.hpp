#pragma once
#include "vector"
#include "iostream"
#include <array>

template<typename T>
int	easyfind(T &obj, int n)
{	//typename olmazsa tipi bağımlı olur değişiklikte hata oluyor. çalışmadan önce hangi T tpde da ilerlediği belli değil.
	typename T::iterator iter = std::find(obj.begin(), obj.end(), n);
	if (iter == obj.end())
		return (-1);
	return (std::distance(obj.begin(), iter));
}

/* T::iterator
kapsayıcılarının bellek adreslerini işaret etmek için kullanılır
Bir vektördeki herhangi bir öğeyi okuyabilen veya değiştirebilen
rastgele erişim yineleyicisi sağlayan bir tür.*/

// iter'ın bir T sınıfı türü olduğunu açıklamak için kullanılır.

/*
std::find
ilk ve son arasındaki tüm öğeleri içeren [ilk,son] aralığıdır.
std::find return
Dönüş Değeri : val ile karşılaştırılan aralıktaki ilk öğenin
yineleyicisi. Hiçbir öğe eşleşmezse, işlev en son döndürür.*/