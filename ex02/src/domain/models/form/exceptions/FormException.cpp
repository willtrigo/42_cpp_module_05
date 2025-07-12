/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:51:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/11 22:29:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high for this form";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low for this form";
}

const char* AForm::AFormSignedException::what() const throw() {
  return "Form is already signed";
}

const char* AForm::AFormNotSignedException::what() const throw() {
  return "Form is not signed";
}
