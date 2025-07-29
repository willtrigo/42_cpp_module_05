/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegrationTests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:38:30 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:05:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRATION_TESTS_HPP
#define INTEGRATION_TESTS_HPP

class IntegrationTests {
 public:
  static void createTestSuite();

 private:
  IntegrationTests(const IntegrationTests&);
  ~IntegrationTests();

  IntegrationTests& operator=(const IntegrationTests&);

  static void testSuccessfulSignedExecuteForm();
  static void testInsufficientGradeToSigingForm();
  static void testAlreadySignedForm();
  static void testInsufficientGradeToExecuteForm();
  static void testAlreadyExecuteForm();
  static void testExecuteWithoutSigningForm();
};

#endif // INTEGRATION_TESTS_HPP
