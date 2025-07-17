/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:05:55 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/17 17:18:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/AForm.hpp"
#include <string>

const std::string PresidentialPardonForm::DEFAULT_TARGET = "Unknow Target";
const std::string PresidentialPardonForm::DEFAULT_FORM_NAME = "Presidential Pardon Form";

PresidentialPardonForm::PresidentialPardonForm()
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(DEFAULT_TARGET) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(other.m_target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->m_target = other.m_target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
