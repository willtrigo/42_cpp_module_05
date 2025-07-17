/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:38:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/11 18:47:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include <cstdlib>

int main() {
  Bureaucrat marvin("Marvin", 42);
  BureaucratPrinter::print(std::cout, marvin);
  return EXIT_SUCCESS;
}
