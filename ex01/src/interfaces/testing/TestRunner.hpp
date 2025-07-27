/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestRunner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:21:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:12:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RUNNER_HPP
#define TEST_RUNNER_HPP

#include "infrastructure/utils/TerminalColor.hpp"
class TestRunner {
 public:
  static void runAllTests();
  static void PrintSection(
    StrColor defaultColor,
    StrColor strColor,
    bool isJumpLIne,
    const std::string& str);
  static void PrintSeparator();

  static const int LINE_SIZE = 80;

 private:
  TestRunner(const TestRunner&);
  ~TestRunner();

  TestRunner& operator=(const TestRunner&);
};

#endif // TEST_RUNNER_HPP
