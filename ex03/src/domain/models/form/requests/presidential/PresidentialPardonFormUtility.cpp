/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFormUtility.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:32:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:59:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"

AForm* PresidentialPardonForm::clone() const {
  return new PresidentialPardonForm(*this);
}

void PresidentialPardonForm::executeTask() const {
  StreamWriter::print(WHITE, BG_PURPLE, this->m_target + " has been pardoned by Zaphod Beeblebrox");
  this->markAsExecuted();
}
