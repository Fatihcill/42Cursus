/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:53:16 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 12:25:57 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string		name;
	Weapon			&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack() const;
};

// fonksiyon tanımından sonra gelen const o fonksiyonun sınıf içerisinde tanımlanan bir
// değeri değiştirmeyeceğini söyler. Bu yapıyı kullanmalıyız çünkü 1) kod okunurluğunu arttırıyor,
// ikincisi geliştirme zamanında yapabileceğimiz bazı hatalarda bizi uyarıyor.
