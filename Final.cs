using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public interface ICommand
{
    void Execute();
}
public class OrderFacade
{
    private OrderMediator mediator;

    public OrderFacade(OrderMediator mediator)
    {
        this.mediator = mediator;
    }

    public void CreateOrder(string itemName, int quantity, string customerInfo)
    {
        ICommand createOrderCommand = new CreateOrderCommand(itemName, quantity, customerInfo, mediator);
        createOrderCommand.Execute();
    }

    public void UpdateOrder(int orderId, Dictionary<string, object> updatedDetails)
    {
        ICommand updateOrderCommand = new UpdateOrderCommand(orderId, updatedDetails, mediator);
        updateOrderCommand.Execute();
    }

    public void CancelOrder(int orderId)
    {
        ICommand cancelOrderCommand = new CancelOrderCommand(orderId, mediator);
        cancelOrderCommand.Execute();
    }
}
public class OrderMediator
{
    public void CoordinatePayment(int orderId, decimal amount)
    {
        Console.WriteLine($"Обработка оплаты заказа {orderId} на сумму ${amount}.");
    }

    public void CoordinateShipping(int orderId, string address)
    {
        Console.WriteLine($"Отправка заказа {orderId} по адресу: {address}.");
    }
}
public class CreateOrderCommand : ICommand
{
    private string itemName;
    private int quantity;
    private string customerInfo;
    private OrderMediator mediator;

    public CreateOrderCommand(string itemName, int quantity, string customerInfo, OrderMediator mediator)
    {
        this.itemName = itemName;
        this.quantity = quantity;
        this.customerInfo = customerInfo;
        this.mediator = mediator;
    }

    public void Execute()
    {
        Console.WriteLine($"Создание заказа на {quantity} единиц товара " + itemName + " от " + customerInfo);
        mediator.CoordinatePayment(1, 100.00m);
        mediator.CoordinateShipping(1, "123 ул. Вчерашнего, Бублики, Новай Страна");
    }
}

public class UpdateOrderCommand : ICommand
{
    private int orderId;
    private Dictionary<string, object> updatedDetails;
    private OrderMediator mediator;

    public UpdateOrderCommand(int orderId, Dictionary<string, object> updatedDetails, OrderMediator mediator)
    {
        this.orderId = orderId;
        this.updatedDetails = updatedDetails;
        this.mediator = mediator;
    }

    public void Execute()
    {
        Console.WriteLine($"Обновление заказа {orderId} с новыми данными.");
        mediator.CoordinatePayment(orderId, 50.00m);

        if (updatedDetails.ContainsKey("Новый адресс"))
        {
            mediator.CoordinateShipping(orderId, updatedDetails["Новый адресс"].ToString());
        }
    }
}

public class CancelOrderCommand : ICommand
{
    private int orderId;
    private OrderMediator mediator;

    public CancelOrderCommand(int orderId, OrderMediator mediator)
    {
        this.orderId = orderId;
        this.mediator = mediator;
    }

    public void Execute()
    {
        Console.WriteLine($"Отмена заказа {orderId}.");
        mediator.CoordinatePayment(orderId, 0.00m);
    }
}
class Program
{
    static void Main(string[] args)
    {
        OrderMediator mediator = new OrderMediator();
        OrderFacade facade = new OrderFacade(mediator);
        facade.CreateOrder("Ноутбук", 1, "Витор Смекалка, vitysmek1978@gmail.com");
        Console.WriteLine();
        Dictionary<string, object> updatedDetails = new Dictionary<string, object>
        {
            { "Айди", 2 },
            { "Новый адресс", "нова вулиця 23, Киев, Украина" }
        };
        facade.UpdateOrder(1, updatedDetails);

        Console.WriteLine();
        facade.CancelOrder(1);
    }
}