/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:52 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/07 17:16:10 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mindless Drone"), _grade(150)
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High: 1 is the maximum grade for a bureaucrat";
}

Bureaucrat::Bureaucrat(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();	
	}
	
	catch(const GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) 
{
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	
}
	
Bureaucrat::~Bureaucrat()
{
}
void	Bureaucrat::IncrementGrade()
{
	
}
void	Bureaucrat::DecrementGrade()
{
	
}
	
int Bureaucrat::getGrade() const
{
	return grade;
}

const std::string Bureaucrat::getName() const
{
	return name;
}