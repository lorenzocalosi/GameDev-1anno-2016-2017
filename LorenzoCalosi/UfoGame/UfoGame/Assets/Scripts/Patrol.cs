using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Patrol : MonoBehaviour {

	public float speed = 1;
	public Transform targetDestination;
	private Transform startPosition;
	private Vector2 destination;
	private bool destinationReached;
	private float distance;
	private Rigidbody2D rgbd2d;

	// Use this for initialization
	void Start () {
		startPosition = this.transform;
		destinationReached = false;
		rgbd2d = this.gameObject.GetComponent<Rigidbody2D> ();
	}

	// Update is called once per frame
	void Update () {
		if (this.transform == targetDestination) {
			destinationReached = true;
		} else if (this.transform == startPosition) {
			destinationReached = false;
		}
		destination = destinationReached? startPosition.position : targetDestination.position;
		distance = Vector2.Distance(this.transform.position, destination);
		rgbd2d.AddForce (destination);
	}

	void OnTriggerEnter2D(Collider2D other) 
	{
		Debug.Log (other.gameObject.CompareTag("Destination"));
		if (other.gameObject.CompareTag ("Destination")) {
			destinationReached = true;
		}
	}
}
