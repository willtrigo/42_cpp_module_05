/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:29:53 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:58:44 by dande-je         ###   ########.fr       */
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

const char* AForm::AFormExecutedException::what() const throw() {
  return "Form is already executed";
}
