/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormUtility.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:33:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:00:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/AForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

AForm* RobotomyRequestForm::clone() const {
  return new RobotomyRequestForm(*this);
}

void RobotomyRequestForm::executeTask() const {
  this->performDrillingNoises();
  const bool robotomySuccess = this->isRobotomySuccessful();
  RobotomyRequestForm::announceRobotomyResult(robotomySuccess);
}

void RobotomyRequestForm::performDrillingNoises() const {
  StreamWriter::print(ORANGE, "* DRILLING NOISES *");
  StreamWriter::print(ORANGE, "* BZZZZZZT... WHIRRRRR... CLANK CLANK *");
  StreamWriter::print(ORANGE, "* MECHANICAL DRILLING SOUNDS *");
}

bool RobotomyRequestForm::isRobotomySuccessful() const {
  const int randomValue = std::rand() % 100;
  return randomValue < 50;
}

void RobotomyRequestForm::announceRobotomyResult(bool success) const {
  const std::string msg = success
    ? this->m_target + " has been robotomized successfully"
    : "Robotomy of " + this->m_target + " has failed";

  const BgColor bgColor = success ? BG_GREEN : BG_RED;
  StreamWriter::print(WHITE, bgColor, msg);
  if (success) {
    this->markAsExecuted();
  }
}
