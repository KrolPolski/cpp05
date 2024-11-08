/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:21:36 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 15:26:32 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	/* data */
public:
	ShrubberyCreationForm(/* args */);
	virtual void execute(Bureaucrat const& executor) override;
	~ShrubberyCreationForm();
};

ShrubberyCreationForm::ShrubberyCreationForm(/* args */)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
