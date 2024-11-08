/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:54:12 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 15:12:15 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("NothingAForm"), _gradeToSign(1), _gradeToExecute(1)
{
}

AForm::AForm(std::string name, int toSign, int toExecute) : _name(name), _gradeToSign(toSign), _gradeToExecute(toExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;	
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

const std::string AForm::getName() const
{
	return _name;
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return "Grade Too High: 1 is the maximum grade for a AForm";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "Grade Too Low: 150 is the minimum grade for a AForm";	
}

void AForm::beSigned(Bureaucrat& drone)
{
	if (drone.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& someAForm)
{
	out << "AForm Name: " << someAForm.getName() << std::endl;
	out << "Grade to be Signed: " << someAForm.getGradeToSign() << std::endl;
	out << "Grade to be Executed: " << someAForm.getGradeToExecute() << std::endl;
	out << "Signature status: " << std::boolalpha << someAForm.getIsSigned() << std::endl;
 	return out; 
}