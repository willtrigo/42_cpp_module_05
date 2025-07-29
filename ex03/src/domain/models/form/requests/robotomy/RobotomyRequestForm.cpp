/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:32:56 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:59:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "domain/models/form/AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

const std::string RobotomyRequestForm::DEFAULT_FORM_NAME = "Robotomy Request Form";

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm(DEFAULT_FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE),
    m_target(target) {
  static bool seedInitialized = false;
  if (!seedInitialized) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    seedInitialized = true;
  }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : AForm(other),
    m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->m_target = other.m_target;
  }
  return *this;
}
