// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/08 15:12:29 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/08 15:12:30 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

class Asteroid
{
	private:
		int x;
		int y;
	public:
		Asteroid(void);
		~Asteroid(void);
		Asteroid( Asteroid const & src );
		Asteroid &operator=( Asteroid const & src);
		bool asteroid_move();

		int getX() const ;
		int getY() const ;
};

#endif
