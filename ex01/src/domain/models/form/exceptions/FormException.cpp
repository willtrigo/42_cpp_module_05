/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:15:08 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:05:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high for this form";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low for this form";
}

const char* Form::FormSignedException::what() const throw() {
  return "Form is already signed";
}

const char* Form::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}
