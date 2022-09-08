/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:53:25 by fcil              #+#    #+#             */
/*   Updated: 2022/09/06 18:55:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/**
 * @brief 
 *	ios::trunc (short for truncate) Dosya açılırken eski bir dosya varsa 
silinir ve yeni bir tane oluşturulur.
 *	eof()	Dosyadan okuma yapılırken dosyanın sonuna gelindiğinde 
 true veya 1 değeri döndürür.
 *	ifstream	dosya okuma modu.
 *	ofstream	dosya yazma modu.
 */
void Replace::replace(std::string const &filename, char *search, char *replace)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	size_t			n;
	size_t			pos;

	infile.open(filename);
	if (!infile)
	{
		std::cout << "couldn't open the file" << std::endl;
		return ;
	}
	outfile.open(filename + ".replace", std::ios::trunc);
	if (!outfile)
	{
		infile.close();
		std::cout << "couldn't open the file" << std::endl;
		return ;
	}
	while (std::getline(infile, line))
	{
		n = strlen(search);
		pos	= line.find(search);
		while (pos != std::string::npos)
		{
			line.erase(pos, n);
			line.insert(pos, replace);
			pos += strlen(replace);
			pos = line.find(search, pos, n);
		}
		outfile << line;
		if (!infile.eof())
			outfile	<< '\n';
	}
	infile.close();
	outfile.close();
}

Replace::Replace()
{
}

Replace::~Replace()
{
}
