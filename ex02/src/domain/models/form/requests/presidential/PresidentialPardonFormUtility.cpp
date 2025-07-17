/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFormUtility.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:06:44 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/12 22:51:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include <iostream>

void PresidentialPardonForm::executeTask() const {
  FormPrinter::printExecute(std::cout, this->m_target + "has been pardoned by Zaphod Beeblebrox");
}
