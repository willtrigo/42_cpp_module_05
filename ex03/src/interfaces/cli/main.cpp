/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:36:33 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:04:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestRunner.hpp"
#include <cstdlib>

int main() {
  TestRunner::runAllTests();
  return EXIT_SUCCESS;
}
