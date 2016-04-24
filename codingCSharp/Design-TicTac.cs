using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    public class Design_TicTac
    {
        
    }

    public class Game
    {
        public int [,] M;

        private bool isPlayer1Turn;

        private IPlayer p1 { get;  set; }

        private IPlayer p2 { get;  set; }

        private GameLogic execution;

        public Game(IPlayer p1, IPlayer p2)
        {
            M = new int[3, 3];
            isPlayer1Turn = true;
            if (p1 == null || p2 == null)
            {

            }

            this.p1 = p1;
            this.p2 = p2;
            execution = new GameLogic(M);
        }

        public void Play()
        {
            if (execution.IsGameOver())
            {
                return;
            }

            var player = isPlayer1Turn ? p1 : p2;
            var location = player.Play(this.M);
            M[location.Item1, location.Item2] = player.Val;
            execution.Print();
            if (execution.HasPlayerWon())
            {
                Console.WriteLine("Won : ");
                return;
            }

            isPlayer1Turn = !isPlayer1Turn;
            Play();
        }
    }

    public class GameLogic
    {
        private int[,] m;

        public GameLogic(int[,] board)
        {
            this.m = board;
        }

        public bool HasPlayerWon()
        {
            return false;
        }

        public bool IsGameOver()
        {
            return false;
        }

        public void Print()
        {

        }
    }

    public interface IPlayer
    {
        Tuple<int, int> Play(int[,] M);

        int Val { get; }
    }

    public class Human : IPlayer
    {
        public int Val { get { return 0; } }

        public Tuple<int, int> Play(int[,]M)
        {
            return new Tuple<int, int>(0,0);
        }
    }

    public class Machine : IPlayer
    {
        public int Val { get { return 1; } }
        public Tuple<int, int> Play(int[,] M)
        {
            return new Tuple<int, int>(0, 0);
        }
    }
}