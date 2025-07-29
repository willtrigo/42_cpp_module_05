/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:50:40 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:01:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_WRITER_HPP
#define FILE_WRITER_HPP

#include <string>
class FileWriter {
 public:
  static void writeToFile(const std::string& filename, const std::string& content);

 private:
  FileWriter(const FileWriter&);
  ~FileWriter();

  FileWriter& operator=(const FileWriter&);
};

#endif // FILE_WRITER_HPP
