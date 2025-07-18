/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:07:11 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 16:41:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "domain/models/form/AForm.hpp"

const std::string RobotomyRequestForm::DEFAULT_TARGET = "Unknow Target";
const std::string RobotomyRequestForm::DEFAULT_FORM_NAME = "Robotomy Request Form";

RobotomyRequestForm::RobotomyRequestForm()
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(DEFAULT_TARGET) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(other.m_target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->m_target = other.m_target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
