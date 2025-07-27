/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:45:13 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:15:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestRunner.hpp"
#include <cstdlib>

int main() {
  TestRunner::runAllTests();
  return EXIT_SUCCESS;
}
