/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:38:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 17:13:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestHelpers.hpp"
#include <cstdlib>

int main() {
	try {
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    AForm *form_pardon = new PresidentialPardonForm("willtrigo");
    form_pardon->beSigned(boss);
    form_pardon->execute(boss);

    AForm *form_robotomy = new RobotomyRequestForm("staff");
    form_robotomy->beSigned(boss);
    form_robotomy->execute(boss);
    form_robotomy->execute(boss);
    form_robotomy->execute(boss);
	} catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
	}
  return EXIT_SUCCESS;
}
