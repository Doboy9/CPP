/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:11 by dboire            #+#    #+#             */
/*   Updated: 2024/07/20 11:47:50 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Random_Materia());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	
	Character* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("random materia");
	me->equip(tmp);
	tmp = src->createMateria("False materia");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(1, *bob);
	src->learnMateria(new Random_Materia());
	tmp = src->createMateria("random materia");
	me->equip(tmp);
	me->use(1, *bob);
	me->use(1, *bob);
	
	Character* me2 = new Character(*me);
	
	me->use(0, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(5, *bob);
	me->unequip(1);
	std::cout << "ME2" << std::endl;
	me2->use(0, *bob);
	me2->use(1, *bob);
	me2->use(2, *bob);
	me2->use(3, *bob);
	me2->use(4, *bob);
	me2->use(5, *bob);
	me2->unequip(1);
	
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	delete me2;
	return 0;
}