/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormGradeException.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:36:30 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/04 20:10:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/form/Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high for this form";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low for this form";
}

const char* Form::FormSignedException::what() const throw() {
  return "Form is already signed";
}
