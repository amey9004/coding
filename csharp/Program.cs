using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{

    class Program
    {
        static void Main(string[] args)
        {
            
        }

        //public List<string> getDirectFriendsForUser(string user);
        
        //public List<string> getAttendedCoursesForUser(string user);

        ///// <summary>
        ///// Lets say each user has n friends and each person has done c courses.
        ///// And there are total C courses which are not done by current user
        ///// Spatial complexity
        /////     atttendedCourses - courses attended by current user - O(c)
        /////     newCourses - new courses which are attended by friends but not by user - O(C)
        /////     friends/uniqueFriends (at any point only 1 variable is active)- all friend circle - O(N^2)
        /////     answer - suggested courses for current user - O(C);
        /////     Assuming c << C. Total space --> O(N^2) + O(C)
        /////     
        ///// Time complexity
        /////     Constructing atttendedCourses -- O(c)
        /////     creating friends list -- O(N * time of getDirectFriendsForUser) ~ O(N^2)
        /////     creating uniqueFriends - O(N^2)
        /////     outer for loop -- O(N^2), inner for loop O(c), lookup in newCourses O(1), inserting/incrementing newCourses O(1)
        /////     creating answer list by sorting O(C logC)
        /////     Total - O(N^2) + O(N^2 * c) + O(C logC)
        ///// 
        ///// The method makes sure that there is no collision while creating uniqueFriends or newCourses object. 
        ///// So all lookup, insertion is in O(1)
        ///// </summary>
        ///// <param name="user"></param>
        ///// <returns></returns>
        //public List<string> getRankedCourses(string user)
        //{
        //    var atttendedCourses = getAttendedCoursesForUser(user).ToDictionary(c => c, c => 1);
        //    Dictionary<string, int> newCourses = new Dictionary<string, int>();
        //    var directFriends = getDirectFriendsForUser(user);
        //    List<string> friends = new List<string>(directFriends);
        //    foreach (var friend in directFriends)
        //    {
        //        friends.Union(getDirectFriendsForUser(friend));
        //    }

        //    HashSet<string> uniqueFriends = new HashSet<string>(friends);
        //    foreach (var friend in uniqueFriends)
        //    {
        //        var courses = getAttendedCoursesForUser(friend);
        //        foreach (var c in courses)
        //        {
        //            if (atttendedCourses.ContainsKey(c))
        //            {
        //                // already attended
        //                continue;
        //            }

        //            if (!newCourses.ContainsKey(c))
        //            {
        //                newCourses[c] = 0;
        //            }

        //            newCourses[c]++;
        //        }
        //    }

        //    var answer = from pair in newCourses
        //                 orderby pair.Value descending
        //                 select pair.Key;

        //    return answer.ToList();
        //}
    }
}
