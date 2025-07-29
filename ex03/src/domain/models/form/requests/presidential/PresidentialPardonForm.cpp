/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:30:51 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:59:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/AForm.hpp"
#include <string>

const std::string PresidentialPardonForm::DEFAULT_FORM_NAME = "Presidential Pardon Form";

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
  : AForm(other),
    m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->m_target = other.m_target;
  }
  return *this;
}
