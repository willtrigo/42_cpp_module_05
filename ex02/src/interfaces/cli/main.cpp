/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:38:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/24 19:46:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestRunner.hpp"
#include <cstdlib>

int main() {
  TestRunner::runAllTests();
  return EXIT_SUCCESS;
}
