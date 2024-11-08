/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:54:12 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 14:05:46 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("NothingForm"), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(std::string name, int toSign, int toExecute) : _name(name), _gradeToSign(toSign), _gradeToExecute(toExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

const int Form::getGradeToSign()
{
	return _gradeToSign;
}

const int Form::getGradeToExecute()
{
	return _gradeToExecute;	
}

bool Form::getIsSigned()
{
	return _isSigned;
}

const std::string Form::getName()
{
	return _name;
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return "Grade Too High: 1 is the maximum grade for a form";
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "Grade Too Low: 150 is the minimum grade for a form";	
}