/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:09:01 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 17:24:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "domain/models/form/AForm.hpp"
#include <string>

const std::string ShrubberyCreationForm::DEFAULT_TARGET = "Unknow Target";
const std::string ShrubberyCreationForm::DEFAULT_FORM_NAME = "Shrubbery Creation Form";

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(DEFAULT_TARGET) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(other.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->m_target = other.m_target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
