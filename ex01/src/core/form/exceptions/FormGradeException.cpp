/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormGradeException.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:36:30 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/05 10:47:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/form/Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high for this form (minimum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low for this form (maximum grade is 150)";
}

const char* Form::FormSignedException::what() const throw() {
  return "Form is already signed";
}
