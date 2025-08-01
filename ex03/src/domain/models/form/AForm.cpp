/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:21:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:00:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/AForm.hpp"
#include <string>

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
  : m_signed(false),
    m_executed(false),
    m_name(name),
    m_gradeToSign(gradeToSign),
    m_gradeToExecute(gradeToExecute) {
   validateAForm(this->m_gradeToSign, this->m_gradeToExecute);
}

AForm::AForm(const AForm& other)
  : m_signed(other.m_signed),
    m_executed(other.m_executed),
    m_name(other.m_name),
    m_gradeToSign(other.m_gradeToSign),
    m_gradeToExecute(other.m_gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
  if (this != &other) {
    const_cast<std::string&>(this->m_name) = other.m_name;
    const_cast<int&>(this->m_gradeToSign) = other.m_gradeToSign;
    const_cast<int&>(this->m_gradeToExecute) = other.m_gradeToExecute;
    this->m_signed = other.m_signed;
    this->m_executed = other.m_executed;
  }
  return *this;
}
