/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:52 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 17:32:03 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade Too High: 1 is the maximum grade for a bureaucrat";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade Too Low: 150 is the minimum grade for a bureaucrat";	
}

Bureaucrat::Bureaucrat() : _name("Mindless Drone"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();		
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) 
{
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& drone)
{
	out << drone.getName() << ", bureaucrat grade " << drone.getGrade() << '.';
	return out; 
}

Bureaucrat::~Bureaucrat()
{
}

void	Bureaucrat::IncrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::DecrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}
	
int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::signForm(AForm& form)
{
	if (_grade <= form.getGradeToSign() && !form.getIsSigned())
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	else if (form.getIsSigned())
	{
		std::cout << getName() << " couldn't sign " << form.getName()
		<< " because the form was already signed." << std::endl;
	}
	else
	{
		std::cout << getName() << " couldn't sign " << form.getName()
		<< " because his grade " << getGrade()
		<< " was lower than the form's requirement of " << form.getGradeToSign() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " could not execute " << form.getName() << " because " << e.what() << std::endl;	
	}
}
