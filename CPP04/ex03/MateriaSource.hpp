/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:01 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:36:17 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include"AMateria.hpp"
#include"IMateriaSource.hpp"

class AMateria;
class IMateriaSource;

class MateriaSource : public IMateriaSource{
private:
	AMateria *_learned_materia[4];
public :
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	
	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const & type);
};

#endif