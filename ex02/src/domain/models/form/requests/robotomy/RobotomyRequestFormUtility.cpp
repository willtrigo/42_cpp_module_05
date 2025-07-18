/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormUtility.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:08:28 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 17:13:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <cstdlib>
#include <ctime>

void RobotomyRequestForm::executeTask() const {
  StreamWriter::print(GREEN, "Beep!... Beep!... Beep!...");
  if ((rand() + clock()) % 2 == 0) {
    StreamWriter::print(BLACK, BG_GREEN, this->m_target + " was sucessfully robotomized");
  } else {
    StreamWriter::print(BLACK, BG_RED, this->m_target + " robotomization falied");
  }
}
