/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamWriter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:47:12 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/17 18:11:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMWRITER_HPP
#define STREAMWRITER_HPP

#include "utils/logging/TerminalColor.hpp"
#include <string>

class StreamWriter {
 public:
  static void print(StrColor strColor, const std::string& str);
  static void print(StrColor strColor, BgColor bgColor, const std::string& str);

 private:
  StreamWriter();
  StreamWriter(const StreamWriter& other);
  StreamWriter& operator=(const StreamWriter& other);
  ~StreamWriter();
};

#endif // STREAMWRITER_HPP
